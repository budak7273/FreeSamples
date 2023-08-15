#pragma once

#include "CoreMinimal.h"
#include "FGSaveInterface.h"
#include "Subsystem/ModSubsystem.h"

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
