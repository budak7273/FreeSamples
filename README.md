# Free Samples

**Multiplayer compatible!**

TODO unhide the mod

TODO radioactive item handling

Whenever you unlock a technology that grants you a recipe, receive a configurable amount of 'free samples' of that recipe. For component crafting recipes, this is the output product. For buildings, this is the ingredients for the building.

The free samples will be inserted into your player inventory. If there isn't enough space, they will be held for claiming later via the `/claimSamples` chat command. You can see what you have pending via the `/listUnclaimed` chat command.

Every player in multiplayer gets a copy of the free sample items.

Customize the following via the mod's config options:

- If the mod's functionality is enabled at all
- The amount of free samples you receive
  - Separate quantity controls for equipment items, buildings, and components
- If items will be given automatically or if you must claim them via the `/claimSamples` chat command.
- How often the mod will attempt to give you items (or remind you about items you haven't claimed yet)
- Specific Schematics, Recipes (TODO), and Items (TODO) to exclude from the mod's functionality
  - By default this includes the Space Elevator and Project Parts.
- TODO if the mod will give you radioactive items as samples

Inspired by [Archipelago's Free Samples system for Factorio](https://mods.factorio.com/mod/FreeSamples) and created primarily for use as a dependency of the [Satisfactory Archipelago mod](https://ficsit.app/mod/Archipelago).

## For Developers

This mod implements some features in C++ to allow for C++ only mods to affect the mod configuration and to add item packages to the sample system.

The source code is public.
