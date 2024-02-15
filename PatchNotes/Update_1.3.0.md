New '/claimSamples force' functionality to place that can't fit in your inventory in crates or on the ground. Bugfixes.




If you enjoy my work, please consider my [completely optional tip jar](https://ko-fi.com/robb4).

## New Stuff

- `/claimSamples` chat command now accepts the `force` argument, causing samples that couldn't fit to be placed in crates near you.
  - Optionally use dropped items instead of crates via the mod's config options.
  - This will never happen automatically to avoid dumping the crates somewhere inconvenient - you must use the chat command to claim oversized samples.
  - Chat warning messages suggest using the force mode of the command if samples couldn't fit

## Changed Stuff

- Improved wording + brevity of the 'your inventory is too full to claim a sample' and 'you have unclaimed samples reminder' chat messages

## Bugfixes

- Fixed that the chat reminder for unclaimed samples would not display in automatic mode if samples couldn't fit in your inventory
