

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FreeSamplePlayerDataComponent.generated.h"

/**
  * C++ parent class so the hook has a class to look up via. All implementation in blueprint.
*/
UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FREESAMPLES_API UFreeSamplePlayerDataComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Copy properties which need to be saved from this component to the passed inactive PlayerState
	UFUNCTION(BlueprintImplementableEvent)
	void CopyProperties(APlayerState* NewPlayerState);

	// Set properties on this component from the passed inactive PlayerState to restore from
	UFUNCTION(BlueprintImplementableEvent)
	void OverrideWith(APlayerState* OldPlayerState);
};
