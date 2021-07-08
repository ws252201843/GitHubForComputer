// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillComponent.h"
#include "Animation/AnimMontage.h"
#include "GameFramework/Character.h"
#include "SkillManagerComponent.h"
// Sets default values for this component's properties
USkillComponent::USkillComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USkillComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USkillComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void USkillComponent::OnCast()
{
	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("SkillComp....OnCast."));
	playAnim();
	onCastImp();
}

void USkillComponent::playAnim()
{
	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("SkillComp....playAnim."));
	if (!skillMontage || !skillMgr) return;
	ACharacter* mainCharacter = Cast<ACharacter>(GetOwner());
	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("SkillComp....mainCharacter."));
	if (!mainCharacter) return;
	
	if (skillMontage != nullptr)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("SkillComp....PlayAnimMontage."));
		mainCharacter->PlayAnimMontage(skillMontage);
	}
	skillMgr->curSkill = this;
}
