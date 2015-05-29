data Tree = Empty | Sym {sym :: Char} | Node {left :: Tree, right :: Tree} deriving (Eq)

instance Show (Tree) where
	show Empty = "e"
	show (Sym a) = show a
	show (Node left right) = 'n':'x':(show left) ++ (show right)


helper :: String -> (Tree, String)
helper ('e':xs) = (Empty, xs)
helper ('\'':a:'\'':xs) = (Sym a, xs)
helper ('n':'x':xs) = result where
									(res1, str1) = helper xs
									(res2, str2) = helper str1
									result = ((Node res1 res2), str2)

readTree str = fst $ helper str

testEqual = (Node (Node (Sym 'a') (Sym 'b')) (Node Empty (Sym 'c'))) == (readTree $ show (Node (Node (Sym 'a') (Sym 'b')) (Node Empty (Sym 'c'))))
testShow = show (Node (Node (Sym 'a') (Sym 'b')) (Node Empty (Sym 'c')))
