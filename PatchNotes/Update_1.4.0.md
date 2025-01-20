Satisfactory 1.0 support. Added ContentTag support. Updated mod icon.




If you enjoy my work, please consider my [completely optional tip jar](https://ko-fi.com/robb4).

## Changed Stuff

- Added [Content Tag](https://docs.ficsit.app/satisfactory-modding/latest/Development/ModLoader/ContentTagRegistry.html) support for mod developers
  - `FreeSamples.Skip` tag can be used to mark schematics, recipes, and items that you don't want to be considered for free samples.
  - Alternative to the `TArray<TSoftClassPtr<UObject>> FreeSamplesAPI_` approach, but there is no tag counterpart for `FreeSamplesAPI_ItemQuantityOverrides`
- Updated mod icon to remove "dust" carried over from the vanilla image used as the base
- Recompiled for 1.0 support (thanks Jarno!)
