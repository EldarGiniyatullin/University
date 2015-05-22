import Test.HUnit

data BST a = Empty | Node {value :: a, left :: BST a, right :: BST a} deriving (Eq)

addValue :: (Ord a, Eq a) => a -> (BST a) -> (BST a)
addValue a Empty = Node a Empty Empty
addValue a (Node val lt rt) | a == val = Node val lt rt
							| a > val  = Node val lt (addValue a rt)
							| a < val  = Node val (addValue a lt) rt

removeValue :: (Ord a, Eq a) => a -> (BST a) -> (BST a)
removeValue a Empty = Empty
removeValue a (Node val lt rt) 	| a < val  = Node val (removeValue a lt) rt
								| a > val  = Node val lt (removeValue a rt)
								| a == val = putRTL lt rt where
											putRTL Empty rtr = rtr
											putRTL tree rtr = putRTL (right tree) rtr


findValue :: (Ord a, Eq a) => a -> (BST a) -> Bool
findValue a Empty = False
findValue a (Node val lt rt)    | a == val = True 
								| a < val  = findValue a lt
								| a > val  = findValue a rt

sizeBST :: (BST a) -> Int
sizeBST Empty = 0
sizeBST (Node _ lt rt) = 1 + sizeBST lt + sizeBST rt

heightBST :: (BST a) -> Int
heightBST Empty = 0
heightBST (Node _ lt rt) = 1 + max (heightBST lt) (heightBST rt)

testTree = Node 
				21
				(Node 
					12 
					(Node 
						8 
						(Node 
							5
							(Node 2 Empty Empty) 
							(Node 6 Empty Empty)) 
						Empty) 
					(Node 
						15 
						Empty 
						(Node 17 Empty Empty)))
				(Node 
					31
					(Node 24 Empty Empty)
					(Node 33 Empty Empty))

assert1 = TestCase (assertEqual "reallyRemoved" False (findValue 21 $ removeValue 21 testTree))
assert5 = TestCase (assertEqual "size" 11 (sizeBST testTree))
assert2 = TestCase (assertEqual "didNotRemoveAnything" 11 (sizeBST $ removeValue 22 testTree))
assert3 = TestCase (assertEqual "reallyAdded" True (findValue 35 $ addValue 35 testTree))
assert4 = TestCase (assertEqual "height" 5 (heightBST testTree))

tests = TestList [TestLabel "reallyRemoved" assert1, TestLabel "didNotRemoveAnything" assert2, TestLabel "reallyAdded" assert3, TestLabel "height" assert4, TestLabel "size" assert5]

main = runTestTT tests

