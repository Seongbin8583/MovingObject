#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ToandFroObject.generated.h"


UCLASS()
class MOVINGOBJECT_API AToandFroObject : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AToandFroObject();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ToandFroObject|Component")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ToandFroObject|Component")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ToandFroObject|Properties")
	float ToandFroSpeed;

	FVector StartLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ToandFroObject|Properties")
	float MaxRange = 800.0f;

	float CurrentOffset = 0.0f;
	bool bMovingForward = true;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
