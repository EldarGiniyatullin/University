import Control.Monad

data Graph v e = Graph [(Int,v)] [(Int,Int,e)]

find :: (a -> Bool) -> [a] -> Bool
find _ [] = False
find f (x:xs) = if (f x) then True else find f xs

minPair :: (Ord a) => ([Int], a) -> ([Int], a) -> ([Int], a)
minPair (xs, x) (ys, y) = if (x < y) then (xs, x) else (ys, y)

searchAll :: (MonadPlus m, Num e) => (Graph v e) -> Int -> Int -> [Int] -> m ([Int], e)
searchAll g@(Graph vl el) src dst list | src == dst = return ([src], 0)
									  | otherwise = dijkstraHelper el where	
	     											dijkstraHelper el = case el of
	     																[] -> mzero
	     																(u, v, cost):es -> if ((src == u) && not (find (v ==) list)) 
	     																						then ((searchAll g v dst (u:list)) >>= (\(path1, cost1) -> return (u:path1, cost + cost1))) `mplus` (dijkstraHelper es)
	     																					else dijkstraHelper es

testGraph = Graph [(1, 'a'), (2, 'b'), (3, 'c'), (4, 'd'), (5, 'e')] [(1, 2, 3), (2, 3, 8), (3, 2, 10), (1, 3, 17), (1, 4, 4), (3, 4, 3), (1, 5, 20), (3, 5, 4), (4, 5, 11)]

minList :: (Ord a, Eq a) => [([Int], a)] -> a -> [([Int], a)] -> ([([Int], a)], a)
minList [] minimal acc = (acc, minimal)
minList (x:xs) minimal acc  | minimal  < xv = minList xs minimal acc
							| minimal == xv = minList xs minimal (x:acc)
							| minimal  > xv = minList xs xv [x] where xv = snd x

testMList = searchAll testGraph 1 5 [] :: [([Int], Int)]
testMMaybe = searchAll testGraph 1 5 [] :: Maybe ([Int], Int)

dijkstra g src dst = minList ((searchAll g src dst []) :: [([Int], Int)]) (maxBound	:: Int) []

main = print (dijkstra testGraph 1 5)
