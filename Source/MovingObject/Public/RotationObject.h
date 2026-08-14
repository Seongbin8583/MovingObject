#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotationObject.generated.h"


UCLASS()
class MOVINGOBJECT_API ARotationObject : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ARotationObject();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "RotationObject|Component")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotationObject|Component")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "RotationObject|Properties")
	float RotationSpeed;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
