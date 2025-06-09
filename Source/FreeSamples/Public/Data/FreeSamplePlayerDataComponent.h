

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FreeSamplePlayerDataComponent.generated.h"

/**
  * C++ parent class, previously so the hook has a class to look up via, now not really needed. All implementation in blueprint.
*/
UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FREESAMPLES_API UFreeSamplePlayerDataComponent : public UActorComponent
{
	GENERATED_BODY()
};
