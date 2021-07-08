// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillManagerComponent.h"

// Sets default values for this component's properties
USkillManagerComponent::USkillManagerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USkillManagerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	if (GetOwner() && GetOwner()->InputComponent)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("BeginPlay....."));
		GetOwner()->InputComponent->BindAction("Skill1", EInputEvent::IE_Pressed, this, &USkillManagerComponent::castSkill1);
		GetOwner()->InputComponent->BindAction("Skill2", EInputEvent::IE_Pressed, this, &USkillManagerComponent::castSkill2);
	}

}


// Called every frame
void USkillManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

USkillComponent* USkillManagerComponent::OnAddSkill(TSubclassOf<USkillComponent> skillClass) 
{

	USkillComponent* skillComp = NewObject<USkillComponent>(GetOwner(), skillClass);

	skillComp->RegisterComponent();
	skillComp->OnInit(this);
	skillArr.Add(skillComp);
	return skillComp;

}

//void USkillManagerComponent::BindSkill(USkillComponent* inSkillComp, USkillComponent*& targetSkillComp)
//{
//	if (!inSkillComp) return;
//	targetSkillComp = inSkillComp;
//}

void USkillManagerComponent::OnCastSkill(USkillComponent* SkillComp)
{
	if (!SkillComp) return;
	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("OnCastSkill....."));
	SkillComp->OnCast();

}