position :: (Num a, Eq b) => b -> [b] -> (a, Bool)
position _ [] = (0, False)
position k (x:xs) = if x == k then (0, True) else (if snd next then (1 + fst next, True) else next) where
	next = position k xs