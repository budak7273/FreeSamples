Allow mods to specify custom quantity overrides for samples of certain items. Only give 10 Power Shards per unlock instead of the user's selected setting (unless it's 0)




## New Stuff

- New system for other mods to affect this mod's functionality (see For Developers below)

## Changed Stuff

- Whenever you receive Power Shards as a free sample, you will now only receive 10 of them, as opposed to whatever your settings are (unless you have the Items category set to 0, in which case there will still be none given).
  - This was done because, under default settings, you would previously receive hundreds of power shards for completing the relevant tree in the MAM - some for each of the 3 slug conversion recipes.
  - Thanks LAJ-47FC9 and AcidXDrop for the suggestion!

## Known Bugs

None, but the following base-game bugs affect this mod's functionality:

- [Multiplayer clients do not display the correct message content from code-generated chat messages](https://discord.com/channels/555424930502541343/1036634533077979146/1141458437021106196)
  - This could cause clients to see useless information when running the `/listUnclaimed` command, for example, but they will still be able to claim samples without issue.

### Questions? Suggestions? Join the [Nog's Mods Discord server](https://discord.gg/uKKFX2tWfh) or leave an issue on the [GitHub issues page](https://github.com/budak7273/FreeSamples/issues) (slower response time)

## For Developers

There is a new method of interfacing with the mod that results in **zero dependencies** on this mod, even at editor time!

FreeSamples will check all mods' Root Game World Modules for fields of the following names at Game World Module Initialization time:

- `TArray<TSoftClassPtr<UObject>> FreeSamples_SkipSchematics`
- `TArray<TSoftClassPtr<UObject>> FreeSamples_SkipRecipes`
- `TArray<TSoftClassPtr<UObject>> FreeSamples_SkipItems`
- `TMap<TSoftClassPtr<UObject>, int> FreeSamples_ItemQuantityOverrides`

If any of these fields are found, the mod will use them to determine which
schematics, recipes, and items to skip when generating samples,
and will use the quantity overrides to determine how many of each item to give.

In order to interface with FreeSamples in this manner,
simply create a field on your mod's Root Game World Module with one of the above names
and populate it with the values you wish to be skipped or overridden.
FreeSamples will use reflection to find and process these values at runtime.
Do note that the game will crash if you have a field with this name that does not match the type above.
(ex. an array of Booleans instead of Soft Class Pointers)

Soft Class References are used so that runtime-generated content (ex. ContentLib) can be listed before it is created.

Example: (TMap of `TSoftClassPtr<UFGItemDescriptor>` to Integer in blueprint)

![Power Shard example](https://i.imgur.com/8S8nUOV.png)
