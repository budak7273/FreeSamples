Adjust the way "inventory too full" warnings are sent to reduce chat spam when a mod slowly unlocks schematics one at a time.




If you enjoy my work, please consider my [completely optional tip jar](https://ko-fi.com/robb4).

## Changed Stuff

- Adjust the way "inventory too full" warnings are sent to reduce chat spam when a mod slowly unlocks schematics one at a time.
  - Previously a refreshable delay of 1 second between messages
  - Now operates on a refreshable delay of 5 seconds, except the first call in those 5 seconds goes through immediately, and any further calls wait (and potentially refresh) the 5 seconds
  - Reduces chat spam in a specific case caused by an unreleased mod
