// Fill out your copyright notice in the Description page of Project Settings.

#include "SkillComponent.h"
#include "SkillManagerComponent.h"
#include "AnimNotify_Skill.h"
void UAnimNotify_Skill::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);
	if (!MeshComp)
	{
		return;
	}

	TInlineComponentArray<USkillManagerComponent*> Components(MeshComp->GetOwner());
	USkillComponent* skill;
	//GEngine->AddOnScreenDebugMessage(-1, 4.0f, FColor:Red, Components.Num());
	for (USkillManagerComponent* skillMgr : Components)
	{
		skill = skillMgr->curSkill;
		if(!skill)
			continue;
		
		UFunction* func = skill->FindFunction(FunctionName);

		if (func)
			skill->ProcessEvent(func, nullptr);
	}

}
