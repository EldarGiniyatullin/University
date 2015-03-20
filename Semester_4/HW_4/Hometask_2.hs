data Tree a = Empty
			| Node a
			| Tree { left :: (Tree a), value :: a, right :: (Tree a) }

foldrTree :: (a -> b -> b) -> b -> (Tree a) -> b
foldrTree _ b Empty = b
foldrTree f b (Node a) = f a b
foldrTree f b tree = foldrTree f (f (value tree) (foldrTree f b (left tree))) (right tree)

foldlTree :: (b -> a -> b) -> b -> (Tree a) -> b
foldlTree _ b Empty = b
foldlTree f b (Node a) = f b a
foldlTree f b tree = foldlTree f (f (foldlTree f b (left tree)) (value tree)) (right tree)