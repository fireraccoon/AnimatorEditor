#DELETE STATE
user clicks "delete" on STATE
STATE Emits "deleteRequest".
SCENE catches signal "deleteRequest"
SCENE deletes STATE.
SCENE Emits "stateDeleted"
INSPECTOR catches "stateDeleted"
INSPECTOR clears itself

# SELECT STATE
user clicks STATE.
STATE emits "stateSelected"
SCENE catches signal "stateSelected"
SCENE emits signal "stateSelected"
INSPECTOR catches "stateSelected"
INSPECTOR inspects STATE



# ADD TRANSITION
user clicks "add transition" on STATE
STATE Emits "transitionInsertionRequest"
SCENE catches signal "transitionInsertionRequest"
SCENE set mode to "InsertTransition"