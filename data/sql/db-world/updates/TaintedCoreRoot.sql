-- Disable root on Tainted Core
UPDATE item_template SET spellid_3 = 0, spelltrigger_3 = 0 WHERE entry = 31088;