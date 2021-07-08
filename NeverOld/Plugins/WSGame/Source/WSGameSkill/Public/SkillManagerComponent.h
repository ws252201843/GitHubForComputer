// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SkillManagerComponent.generated.h"

class USkillComponent;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent),Blueprintable )
class WSGAMESKILL_API USkillManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USkillManagerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite)
	TArray<USkillComponent*> skillArr;

	USkillComponent* curSkill;

	UFUNCTION(BlueprintCallable)
	virtual USkillComponent* OnAddSkill(TSubclassOf<USkillComponent> skillClass);
	
	UFUNCTION(BlueprintCallable)
	virtual void OnCastSkill(USkillComponent* SkillComp);




	virtual void castSkill1() { 
		//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("castSkill.....111111"));
		OnCastSkill(skillArr[0]);};

	virtual void castSkill2() { 
		//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("castSkill....22222."));
		OnCastSkill(skillArr[1]); };

};
