user clicks "delete" on STATE
STATE Emits "deleteRequest".
SCENE catches signal "deleteRequest"
SCENE deletes STATE.
SCENE Emits "stateDeleted"
INSPECTOR catches "stateDeleted"
INSPECTOR clears itself


user clicks STATE.
STATE emits "stateSelected"
SCENE catches signal "stateSelected"
SCENE emits signal "stateSelected"
INSPECTOR catches "stateSelected"
INSPECTOR inspects STATE