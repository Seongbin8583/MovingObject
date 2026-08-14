#include "UpDownObject.h"


AUpDownObject::AUpDownObject()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);


	PrimaryActorTick.bCanEverTick = true;
	UpDownSpeed = 90.0f;
}

void AUpDownObject::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	CurrentOffset = 0.0f;
	MaxRange = 1600; UpDownSpeed;

	SetActorLocation(FVector(920.0f, -800.0f, 80.0f));
	SetActorScale3D(FVector(3.0f, 2.0f, 1.0f));
}

void AUpDownObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(UpDownSpeed))
	{
		FVector UpDir = GetActorUpVector();

		float DeltaOffset = UpDownSpeed * DeltaTime;

		if (bMovingUp)
		{
			CurrentOffset += DeltaOffset;
		}
		else
		{
			CurrentOffset -= DeltaOffset;
		}
		if (CurrentOffset >= MaxRange)
		{
			CurrentOffset = MaxRange; bMovingUp = false;
		}
		if (CurrentOffset <= -MaxRange)
		{
			CurrentOffset = -MaxRange; bMovingUp = true;
		}
		FVector NewLocation = StartLocation + UpDir * CurrentOffset;
		SetActorLocation(NewLocation);
	}
}

