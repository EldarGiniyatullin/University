data Tree a = Empty
			| Node a
			| Tree { left :: (Tree a), value :: a, right :: (Tree a) }

height :: (Tree a) -> (Integer -> Integer -> Integer) -> Integer
height Empty _ = 0
height (Node a) _ = 0
height tree f = 1 + f (height (left tree) f) (height (right tree) f)

minHeight :: (Tree a) -> Integer
minHeight tree = height tree min

maxHeight :: (Tree a) -> Integer
maxHeight tree = height tree max