// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class Cpp_Arcada_01Target : TargetRules
{
	public Cpp_Arcada_01Target(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "Cpp_Arcada_01" } );
	}
}
