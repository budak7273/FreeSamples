# Free Samples

**Multiplayer compatible!**

<!-- TODO unhide the mod

TODO test with Awesome Shop -->

Whenever you unlock a technology that grants you a recipe,
receive a configurable amount of 'free samples' of that recipe.
For equipment and component crafting recipes, this is the output product.
For buildings, this is the ingredients for the building.
Every player in multiplayer gets a copy of the free sample items.
Compatible with all mods that add recipes.

The free sample packages will be inserted directly into your player inventory.
If there isn't enough space, they will be held for claiming later.
You can also opt to require manually claiming them via the `/claimSamples` chat command.
You can see what packages you have pending via the `/listUnclaimed` chat command.

Inspired by [Archipelago's Free Samples system for Factorio](https://mods.factorio.com/mod/FreeSamples) and created primarily for use as a dependency of the [Satisfactory Archipelago mod](https://ficsit.app/mod/Archipelago).

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

- [Clients do not receive the correct chat messages](TODO QA LINK)
<!-- https://discord.com/channels/555424930502541343/1036634533077979146/1141458437021106196 -->

## For Developers

This mod automatically functions with every schematic except those granted before the subsystem initializes, so schematics rewarded very early (ex. Starting Recipes) will not be considered for samples. You can also add schematics, recipes, and items to the mod's exclude lists via the C++ or Blueprint API.

The source code is public.

By enabling debug mode you gain access to the chat command `/cc_resetSamples` which will reset the subsystem's saved reward data. This is useful for testing the mod's functionality. Using [Mam Enhancer](https://ficsit.app/mod/MAMTips)'s debug mode makes it very easy to grant/revoke schematics for testing the exclude lists, for example.

This mod implements some features in C++ to allow for C++ only mods to affect the mod's configuration.
Highlights include:

- A getter exists for the mod's subsystem, which is backed by a C++ class
- The config struct C++ header is generated
- Mods can interact with the subsystem's ignore lists to add/remove items from them separate from the user's selected configuration options

Future plans:

- Ability to add arbitrary item packages to the sample system (that aren't associated with schematics)
