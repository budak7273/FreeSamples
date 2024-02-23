#include "Subsystem/FreeSamplesSubsystem.h"

bool AFreeSamplesSubsystem::PlayerClaimSamples_Implementation(bool manuallyTriggered, APlayerState* player, bool dropExcessOnGround) {
	UE_LOG(LogFreeSamplesCpp, Error, TEXT("No C++ implementation yet for PlayerClaimSamples_Implementation, make sure this is overridden in Blueprint"));
	return false;
}

AFreeSamplesSubsystem* AFreeSamplesSubsystem::Get(UObject* WorldContext) {
	// This approach would break if a C++ version was spawned or was persisted via save game
	// The blueprint version descends from this class, so it gets found instead as long as it got spawned properly
	return Cast<AFreeSamplesSubsystem>(UGameplayStatics::GetActorOfClass(WorldContext, StaticClass()));
}
