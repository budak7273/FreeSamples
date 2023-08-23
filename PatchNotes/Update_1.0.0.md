Whenever you unlock a technology that grants you a recipe, receive a configurable amount of 'free samples' items of that recipe. Multiplayer supported!




# Free Samples

**Multiplayer compatible!**

Whenever you unlock a technology that grants you a recipe,
receive a configurable amount of 'free samples' of that recipe.
For equipment and component crafting recipes, this is the output product.
For buildings, this is the ingredients for the building.
Every player in multiplayer gets a copy of the free sample items.

For example, under the mod's default settings,
unlocking the Nobelisk Detonator MAM node will give you one Nobelisk Detonator and 50 Nobelisk,
unlocking the Jump Pads T2 milestone will give you the ingredients to construct 5 Jump Pads and 5 U-Jelly Landing Pads, etc.

The free sample packages will be inserted directly into your player inventory.
If there isn't enough space, they will be held for claiming later.
You can also opt to require manually claiming them via the `/claimSamples` chat command.
You can see what packages you have pending via the `/listUnclaimed` chat command.

Should be compatible with all mods that add recipes and schematics,
including those that do so via runtime content generation like [ContentLib](https://ficsit.app/mod/ContentLib).
The mod does not retroactively provide samples for schematics unlocked before it was installed.

Inspired by [Archipelago's Free Samples system for Factorio](https://mods.factorio.com/mod/FreeSamples)
<!-- and created primarily for use as a dependency of the [Satisfactory Archipelago mod](https://ficsit.app/mod/Archipelago). -->

## Configuration

Customize the following via the mod's config options:

- If the mod's functionality is enabled at all
- The amount of free samples you receive
  - Separate quantity controls for equipment items, buildings, and components
  - By default: 1 equipment item, 5 sets of building ingredients, and 1 stack of component items
- If items will be given automatically, or if you must claim them via the `/claimSamples` chat command.
  - By default: Items automatically given
- How often the mod will attempt to give you items (or remind you about items you haven't claimed yet)
  - By default: Every 60 seconds, or whenever a new schematic is unlocked.
- If the mod will give you radioactive items as samples
  - By default: Exclude radioactive items
- Specific Schematics, Recipes, and Items to exclude from free sample consideration
  - By default: Don't supply the construction cost of the Space Elevator, and don't supply samples when you unlock the default recipes for Project Parts.
  - Easy-to-use config interface helps you make these exclude lists yourself by searching for loaded recipes
  - ![Screenshot of widget](https://i.imgur.com/ZyLu894.png)

## Known Bugs

None, but the following base-game bugs affect this mod's functionality:

- [Multiplayer clients do not display the correct message content from code-generated chat messages](https://discord.com/channels/555424930502541343/1036634533077979146/1141458437021106196)
  - This could cause clients to see useless information when running the `/listUnclaimed` command, for example, but they will still be able to claim samples without issue.

### Questions? Suggestions? Join the [Nog's Mods Discord server](https://discord.gg/uKKFX2tWfh) or leave an issue on the [GitHub issues page](https://github.com/budak7273/FreeSamples/issues) (slower response time)

## For Developers

This mod automatically functions with every schematic except those granted before the subsystem initializes,
so schematics rewarded very early (ex. Starting Recipes) will not be considered for samples.
You can also add schematics, recipes, and items to the mod's exclude lists via the C++ or Blueprint API.

The source code is public.

By enabling debug mode you gain access to the chat command `/cc_resetSamples` which will reset the subsystem's saved reward data, as well as the caller's. This is useful for testing the mod's functionality.
You can also use `/cc_samplesDebugData` to send info to the logs about the global and command caller's samples.
Using [Mam Enhancer](https://ficsit.app/mod/MAMTips)'s debug mode makes it very easy to grant/revoke schematics for testing the exclude lists, for example.

This mod implements some features in C++ to allow for C++ only mods to affect the mod's configuration.
Highlights include:

- A getter exists for the mod's subsystem, which is backed by a C++ class
- The config struct C++ header is generated
- Mods can interact with the subsystem's ignore lists to add/remove items from them separate from the user's selected configuration options

Future plans:

- Ability to add arbitrary item packages to the sample system (that aren't associated with schematics)
- Reflection to check other mods' Game World Modules for a named field containing data schematics/items/recipes to ignore so they don't need to directly reference this mod in any way
