#include "ToandFroObject.h"


AToandFroObject::AToandFroObject()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	PrimaryActorTick.bCanEverTick = true;
	ToandFroSpeed = 250.0f;
}

void AToandFroObject::BeginPlay()
{
	Super::BeginPlay();

	CurrentOffset = 0.0f;
	bMovingForward = false;
	MaxRange = 1600; ToandFroSpeed;

	SetActorLocation(FVector(900.0f, 800.0f, 180.0f));

	StartLocation = GetActorLocation();

	SetActorScale3D(FVector(2.0f, 2.0f, 1.0f));
	
}

void AToandFroObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!FMath::IsNearlyZero(ToandFroSpeed))
	{
		FVector ForwardDir = GetActorForwardVector();

		float DeltaOffset = ToandFroSpeed * DeltaTime;

		if (bMovingForward)
		{
			CurrentOffset += DeltaOffset;
		}
		else
		{
			CurrentOffset -= DeltaOffset;
		}
		if (CurrentOffset >= MaxRange)
		{
			CurrentOffset = MaxRange; bMovingForward = false;
		}
		if (CurrentOffset <= -MaxRange)
		{
			CurrentOffset = -MaxRange; bMovingForward = true;
		}
		FVector NewLocation = StartLocation + ForwardDir * CurrentOffset;
		SetActorLocation(NewLocation);
	}
}


