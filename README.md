# KettisLogicDriverExtension

# Utility
 A small selection of helpfull helper functions which will help you.
 
<img width="1639" alt="UnrealEditor_1316" src="https://github.com/Kettenotter/KettisLogicDriverExtension/assets/32515271/1bf7112d-4b12-45a3-b207-0dfb0611014b">

<img width="600" alt="UnrealEditor_1321" src="https://github.com/Kettenotter/KettisLogicDriverExtension/assets/32515271/76bd9ad1-930b-479f-a07a-1d462a70a140">


How it compares to the default cast to nodes and the get context:

<img width="995" alt="UnrealEditor_1314" src="https://github.com/Kettenotter/KettisLogicDriverExtension/assets/32515271/14e8637e-8bd4-4143-a215-2d9e91b5a1b1">
<img width="1178" alt="UnrealEditor_1315" src="https://github.com/Kettenotter/KettisLogicDriverExtension/assets/32515271/7d5d1a51-e811-4bf5-90ab-c7614583becf">


# Gameplay Ability System

The nodes above for getting the ASC.

Optimized transitions which work without ticking in the TransitionGameplayAbilityGeneric.h:

- Gameplay Tag
- Gameplay Tag Query
- Attribute reach Zero

A specific example which will compile out because it depends on my project specific Attribute Sets in the TransitionGameplayAbilitySpecific.h:
- On can pay mana

All of the transitions also have:
- assigning icons from a data table
- a toggle for inverting the condition, the icon will change color
- a toggle which will disable event based logic (mostly for debugging)
- the icon will turn transparent if the condition is invalid (for exmaple no gameplay tag provided

https://github.com/Kettenotter/KettisLogicDriverExtension/assets/32515271/d92648ad-b90b-4ff3-8c26-e924643bcfaa
