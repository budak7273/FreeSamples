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
struct FFreeSamplesConfigurationStruct_Debugging;

USTRUCT(BlueprintType)
struct FFreeSamplesConfigurationStruct_Global {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    bool Enabled{};

    UPROPERTY(BlueprintReadWrite)
    bool PerPlayer{};

    UPROPERTY(BlueprintReadWrite)
    bool RequireCommand{};

    UPROPERTY(BlueprintReadWrite)
    float UnclaimedUpdateInterval{};

    UPROPERTY(BlueprintReadWrite)
    bool UseDroppedItemsInsteadOfCrates{};
};

USTRUCT(BlueprintType)
struct FFreeSamplesConfigurationStruct_Equipment {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    int32 Quantity{};
};

USTRUCT(BlueprintType)
struct FFreeSamplesConfigurationStruct_Buildings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    int32 Quantity{};
};

USTRUCT(BlueprintType)
struct FFreeSamplesConfigurationStruct_Parts {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    int32 Quantity{};
};

USTRUCT(BlueprintType)
struct FFreeSamplesConfigurationStruct_Exclude {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    bool SkipRadioactive{};

    UPROPERTY(BlueprintReadWrite)
    TArray<FString> SkipRecipes{};

    UPROPERTY(BlueprintReadWrite)
    TArray<FString> SkipItems{};

    UPROPERTY(BlueprintReadWrite)
    TArray<FString> SkipSchematics{};

    UPROPERTY(BlueprintReadWrite)
    bool _HasBeenEditedByUser{};
};

USTRUCT(BlueprintType)
struct FFreeSamplesConfigurationStruct_Debugging {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    bool EnableDebug{};
};

/* Struct generated from Mod Configuration Asset '/FreeSamples/Configuration/FreeSamplesConfiguration' */
USTRUCT(BlueprintType)
struct FFreeSamplesConfigurationStruct {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    FFreeSamplesConfigurationStruct_Global Global{};

    UPROPERTY(BlueprintReadWrite)
    FFreeSamplesConfigurationStruct_Equipment Equipment{};

    UPROPERTY(BlueprintReadWrite)
    FFreeSamplesConfigurationStruct_Buildings Buildings{};

    UPROPERTY(BlueprintReadWrite)
    FFreeSamplesConfigurationStruct_Parts Parts{};

    UPROPERTY(BlueprintReadWrite)
    FFreeSamplesConfigurationStruct_Exclude Exclude{};

    UPROPERTY(BlueprintReadWrite)
    FFreeSamplesConfigurationStruct_Debugging Debugging{};

    /* Retrieves active configuration value and returns object of this struct containing it */
    static FFreeSamplesConfigurationStruct GetActiveConfig(UObject* WorldContext) {
        FFreeSamplesConfigurationStruct ConfigStruct{};
        FConfigId ConfigId{"FreeSamples", ""};
        if (const UWorld* World = GEngine->GetWorldFromContextObject(WorldContext, EGetWorldErrorMode::ReturnNull)) {
            UConfigManager* ConfigManager = World->GetGameInstance()->GetSubsystem<UConfigManager>();
            ConfigManager->FillConfigurationStruct(ConfigId, FDynamicStructInfo{FFreeSamplesConfigurationStruct::StaticStruct(), &ConfigStruct});
        }
        return ConfigStruct;
    }
};

