#pragma once

#include "CoreMinimal.h"
#include "FGSaveInterface.h"
#include "Subsystem/ModSubsystem.h"
#include "Subsystem/SubsystemActorManager.h"
#include "FGSchematic.h"
#include "FGRecipe.h"
#include "Resources/FGItemDescriptor.h"

#include "FreeSamples.h"
#include "FreeSamplesSubsystem.generated.h"

/**
 * 
 */
UCLASS(Abstract, Blueprintable)
class FREESAMPLES_API AFreeSamplesSubsystem : public AModSubsystem, public IFGSaveInterface
{
	GENERATED_BODY()

	// Begin IFGSaveInterface
	virtual void PreSaveGame_Implementation(int32 saveVersion, int32 gameVersion) override {};
	virtual void PostSaveGame_Implementation(int32 saveVersion, int32 gameVersion) override {};
	virtual void PreLoadGame_Implementation(int32 saveVersion, int32 gameVersion) override {};
	virtual void PostLoadGame_Implementation(int32 saveVersion, int32 gameVersion) override {};
	virtual void GatherDependencies_Implementation(TArray< UObject* >& out_dependentObjects) override {};
	virtual bool NeedTransform_Implementation() override { return false; };
	virtual bool ShouldSave_Implementation() const override { return true; };
	// End IFSaveInterface

public:

	// Schematics in this list will be ignored by Free Sample consideration
	// Will be combined with the user's chosen config for the mod at runtime
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		TSet<TSubclassOf<UFGSchematic>> BlacklistedSchematics;

	// Schematics in this list will be ignored by Free Sample consideration
	// Will be combined with the user's chosen config for the mod at runtime
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		TSet<TSubclassOf<UFGRecipe>> BlacklistedRecipes;

	// Schematics in this list will be ignored by Free Sample consideration
	// Will be combined with the user's chosen config for the mod at runtime
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		TSet<TSubclassOf<UFGItemDescriptor>> BlacklistedItems;

	// Will radioactive items be excluded from free samples
	// Set from the user's config but you can be overwritten at runtime
	UPROPERTY(BlueprintReadWrite)
		bool ExcludeRadioactiveSamples;

public:
	// C++ getter for the subsystem - the real one is implemented in Blueprint,
	// so calling this function gets you the "real one" that inherits from the
	// C++ class and not the C++ abstract class.
	UFUNCTION(BlueprintPure, Category = "FreeSamples", DisplayName = "GetFreeSamplesSubsystem", Meta = (DefaultToSelf = "WorldContext"))
		static AFreeSamplesSubsystem* Get(class UObject* WorldContext);

	// Trigger trying to claim samples for a player.
	// Claims as many packages as they have space for in their entirety.
	// Returns false if at least one of the packages couldn't fit.
	// The packages that couldn't fit remain in the queue. Those that did fit are moved to Claimed.
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		bool PlayerClaimSamples(bool manuallyTriggered, APlayerState* player);

	// TODO add schematic to internal queue
	// Returns true if added, false if was already present or already awarded in the past
	// UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	// bool AddSchematic(TSubclassOf<UFGSchematic> schematic);

	// TODO add arbitrary item amount to internal queue
	// Returns true if added, false if was already present or already awarded in the past
	// uniqueIdentifier is a map key and allows adding multiple instances of the same itemAmount
	// UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	// bool AddArbitraryItemAmountPackage(string uniqueIdentifier, ItemAmount itemAmount);

	// TODO add item player inventory
	// Returns true if added, false if it wouldn't fit
	// UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	// bool AddItemsToPlayerInventory(ItemAmount? InventoryItemStruct?, APlayerState* player);

	// TODO move the processing of sets/arrays into cpp for performance if it becomes a problem
};
