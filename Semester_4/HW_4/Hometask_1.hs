import Test.HUnit

data Tree a = Empty
			| Node a
			| Tree { left :: (Tree a), value :: a, right :: (Tree a) }

find :: (a -> Bool) -> (Tree a) -> [a]
find f Empty = []
find f (Node a) = if (f a) then [a] else []
find f tree = (find f (left tree)) ++ (if (f (value tree)) then [(value tree)] else []) ++ (find f (right tree))

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


assert1 = TestCase (assertEqual "testDivide3" [6, 12, 15, 21, 24, 33] (find ((== 0).(`mod` 3)) testTree))
assert2 = TestCase (assertEqual "testMoreThan14" [15, 17, 21, 24, 31, 33] (find (> 14) testTree))

tests = TestList [TestLabel "test1" assert1, TestLabel "test2" assert2]  

main = runTestTT tests