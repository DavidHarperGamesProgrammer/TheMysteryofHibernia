// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class Mystery_of_HiberniaEditorTarget : TargetRules
{
	public Mystery_of_HiberniaEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "Mystery_of_Hibernia" } );
	}
}
