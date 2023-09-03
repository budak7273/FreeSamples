#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "FreeSamples.h"
#include "FreeSamplesBPLib.generated.h"

UCLASS()
class FREESAMPLES_API UFreeSamplesBPLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
		static void ReflectionTesting(TSubclassOf<UObject> clazz);

	UFUNCTION(BlueprintCallable)
		static TArray<TSoftClassPtr<UObject>> ArrayReflectionTesting(TSubclassOf<UObject> clazz);
	
	// Retrieve the values on a field on this object with the name propertyName of exactly the type TArray<TSoftClassPtr<UObject>>
	// Used for cross-mod compatibility without the other side needing to know about this mod.
	// Success is false if something went wrong
	// Crashes if the property isn't exactly the expected type
	UFUNCTION(BlueprintCallable, Category = "Reflection|FreeSamples")
		static TArray<TSoftClassPtr<UObject>> GetArbitrarySoftClassArray(bool& out_Success, FName propertyName, UObject* onObject);

	// Retrieve the values on a field on this object with the name propertyName of exactly the type TMap<TSoftClassPtr<UObject>, int>
	// Used for cross-mod compatibility without the other side needing to know about this mod.
	// Success is false if something went wrong
	// Crashes if the property isn't exactly the expected type
	UFUNCTION(BlueprintCallable, Category = "Reflection|FreeSamples")
		static TMap<TSoftClassPtr<UObject>, int> GetArbitrarySoftClassIntMap(bool& out_Success, FName propertyName, UObject* onObject);

	// Returns true if the object has a property of the given name of any type
	UFUNCTION(BlueprintCallable, Category = "Reflection|FreeSamples")
		static bool HasProperty(FName propertyName, UObject* onObject);
};
