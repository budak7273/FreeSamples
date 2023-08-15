#pragma once
#include "CoreMinimal.h"
#include "Configuration/ConfigManager.h"
#include "Engine/Engine.h"
#include "FreeSamplesConfigurationStruct.generated.h"

struct FFreeSamplesConfigurationStruct_Global;
struct FFreeSamplesConfigurationStruct_Equipment;
struct FFreeSamplesConfigurationStruct_Buildings;
struct FFreeSamplesConfigurationStruct_Parts;
struct FFreeSamplesConfigurationStruct_Exclude;

USTRUCT(BlueprintType)
struct FFreeSamplesConfigurationStruct_Global {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    bool Enabled;

    UPROPERTY(BlueprintReadWrite)
    bool PerPlayer;

    UPROPERTY(BlueprintReadWrite)
    bool RequireCommand;

    UPROPERTY(BlueprintReadWrite)
    float UnclaimedUpdateInterval;
};

USTRUCT(BlueprintType)
struct FFreeSamplesConfigurationStruct_Equipment {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    int32 Quantity;
};

USTRUCT(BlueprintType)
struct FFreeSamplesConfigurationStruct_Buildings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    int32 Quantity;
};

USTRUCT(BlueprintType)
struct FFreeSamplesConfigurationStruct_Parts {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    int32 Quantity;
};

USTRUCT(BlueprintType)
struct FFreeSamplesConfigurationStruct_Exclude {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    TArray<FString> SkipSchematics;

    UPROPERTY(BlueprintReadWrite)
    TArray<FString> SkipRecipes;

    UPROPERTY(BlueprintReadWrite)
    TArray<FString> SkipItems;
};

/* Struct generated from Mod Configuration Asset '/FreeSamples/Configuration/FreeSamplesConfiguration' */
USTRUCT(BlueprintType)
struct FFreeSamplesConfigurationStruct {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    FFreeSamplesConfigurationStruct_Global Global;

    UPROPERTY(BlueprintReadWrite)
    FFreeSamplesConfigurationStruct_Equipment Equipment;

    UPROPERTY(BlueprintReadWrite)
    FFreeSamplesConfigurationStruct_Buildings Buildings;

    UPROPERTY(BlueprintReadWrite)
    FFreeSamplesConfigurationStruct_Parts Parts;

    UPROPERTY(BlueprintReadWrite)
    FFreeSamplesConfigurationStruct_Exclude Exclude;

    /* Retrieves active configuration value and returns object of this struct containing it */
    static FFreeSamplesConfigurationStruct GetActiveConfig() {
        FFreeSamplesConfigurationStruct ConfigStruct{};
        FConfigId ConfigId{"FreeSamples", ""};
        UConfigManager* ConfigManager = GEngine->GetEngineSubsystem<UConfigManager>();
        ConfigManager->FillConfigurationStruct(ConfigId, FDynamicStructInfo{FFreeSamplesConfigurationStruct::StaticStruct(), &ConfigStruct});
        return ConfigStruct;
    }
};

