-- Correct the time for the Kalu'ak Fishing Derby
UPDATE game_event SET start_time = '2024-03-16 14:00:00' WHERE eventEntry IN (63, 64);