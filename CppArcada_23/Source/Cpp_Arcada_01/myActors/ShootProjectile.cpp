// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootProjectile.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/DamageType.h"
#include "GameFramework/Pawn.h"

// Sets default values
AShootProjectile::AShootProjectile():
	fProjectielSpeed(1000.f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	RootComponent = SphereCollision;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(SphereCollision, NAME_None);
	StaticMesh->SetCollisionProfileName("NoCollision");


}

// Called when the game starts or when spawned
void AShootProjectile::BeginPlay()
{
	Super::BeginPlay();

	if (GetOwner())
	{
		SphereCollision->IgnoreActorWhenMoving(GetOwner(), true);
	}

	SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &AShootProjectile::OnOverlap);
	
}

// Called every frame
void AShootProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalOffset(FVector(fProjectielSpeed*DeltaTime, 0.f, 0.f));

}

void AShootProjectile::OnOverlap(class UPrimitiveComponent* OverlapedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool Sweet, const  FHitResult& Hit)
{

	// UE_LOG(LogTemp, Log, TEXT("OnOverlap"));
	if (!GetOwner()) return;

	APawn* PawnOwner = Cast<APawn>(GetOwner());

	if (!PawnOwner) return;

	AController* Instigator = PawnOwner->GetController();

	UGameplayStatics::ApplyDamage(OtherActor, Damage, Instigator, this, UDamageType::StaticClass());

	Destroy();

}