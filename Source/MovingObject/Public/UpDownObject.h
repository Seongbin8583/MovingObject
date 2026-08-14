#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UpDownObject.generated.h"


UCLASS()
class MOVINGOBJECT_API AUpDownObject : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AUpDownObject();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UpDownObject|Component")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UpDownObject|Component")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UpDownObject|Properties")
	float UpDownSpeed;

	FVector StartLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ToandFroObject|Properties")
	float MaxRange = 800.0f;

	float CurrentOffset = 0.0f;
	bool bMovingUp = true;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};