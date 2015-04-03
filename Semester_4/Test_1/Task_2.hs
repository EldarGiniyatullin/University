import Test.HUnit
import Test.QuickCheck

data Tree a = Empty
			| Node a
			| Tree { left :: (Tree a), value :: a, right :: (Tree a) }

find :: (a -> Bool) -> (Tree a) -> [a] -> [a]
find f Empty acc = acc
find f (Node a) acc = if (f a) then (a:acc) else []
find f tree acc = find f (right tree) (if (f (value tree)) then ((value tree):(find f (left tree) acc)) else (find f (left tree) acc))

negativeTree :: (Num a, Ord a) => (Tree a) -> [a]
negativeTree tree = find (< 0) tree []