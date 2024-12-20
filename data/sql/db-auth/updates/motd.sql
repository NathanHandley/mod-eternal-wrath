DELETE FROM `motd` WHERE `realmid` = -1;
INSERT INTO `motd` (`realmid`, `text`) VALUES (-1, 'Welcome to Eternal Wrath');
