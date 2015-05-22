import Test.HUnit

data Tree a = Empty
			| Node a
			| Tree { left :: (Tree a), value :: a, right :: (Tree a) }

find :: (a -> Bool) -> (Tree a) -> [a]
find f tree  = findH f tree [] where
				findH :: (a -> Bool) -> (Tree a) -> [a] -> [a]
				findH f Empty acc = acc
				findH f (Node a) acc = if (f a) then (a:acc) else acc
				findH f tree acc = findH f (right tree) (if (f (value tree)) then ((value tree):(findH f (left tree) acc)) else (findH f (left tree) acc))

testTree = Tree 
				(Tree 
					(Tree 
						(Tree 
							(Node 2) 
							5 
							(Node 6)) 
						8 
						Empty) 
					12 
					(Tree 
						Empty 
						15 
						(Node 17)))
				21
				(Tree 
					(Node 24)
					31
					(Node 33))


assert1 = TestCase (assertEqual "testDivide3" [33, 24, 21, 15, 12, 6] (find ((== 0).(`mod` 3)) testTree))
assert2 = TestCase (assertEqual "testMoreThan14" [33, 31, 24, 21, 17, 15] (find (> 14) testTree))

tests = TestList [TestLabel "test1" assert1, TestLabel "test2" assert2]  

main = runTestTT tests