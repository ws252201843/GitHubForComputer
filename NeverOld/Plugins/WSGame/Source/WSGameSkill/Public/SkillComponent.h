// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SkillComponent.generated.h"

class USkillManagerComponent;
class UAnimMontage;
UCLASS(Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class WSGAMESKILL_API USkillComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USkillComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite)
	USkillManagerComponent* skillMgr;
	UFUNCTION(BlueprintCallable)
	virtual void OnInit(USkillManagerComponent* _skillMgr) {skillMgr = _skillMgr;};
	UFUNCTION(BlueprintCallable)
	virtual void OnCast();

	UFUNCTION(BlueprintImplementableEvent)
	void onCastImp();
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UAnimMontage* skillMontage;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UDamageType* damageType;


	UFUNCTION(BlueprintCallable)
	void playAnim();
};
