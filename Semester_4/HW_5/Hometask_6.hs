import Test.HUnit

data Polynom a = Param | Con {number :: a} | (Polynom a) :+: (Polynom a) | (Polynom a) :-: (Polynom a) | (Polynom a) :*: (Polynom a) | (Polynom a) :/: (Polynom a)

result :: (Num a, Integral a, Fractional a) => a -> (Polynom a) -> a
result x Param = fromIntegral x
result _ (Con num) = fromIntegral num
result x (tree1 :+: tree2) = (fromIntegral $ result x tree1) + (fromIntegral $ result x tree2)
result x (tree1 :-: tree2) = (fromIntegral $ result x tree1) - (fromIntegral $ result x tree2)
result x (tree1 :*: tree2) = (fromIntegral $ result x tree1) * (fromIntegral $ result x tree2)
result x (tree1 :/: tree2) = (fromIntegral $ result x tree1) / (fromIntegral $ result x tree2)

dx :: (Num a, Eq a) => (Polynom a) -> (Polynom a)
dx pol = simpleGG (dxH pol)

dxH :: (Num a) => (Polynom a) -> (Polynom a)
dxH Param = Con 1
dxH (Con _) = Con 0
dxH (tree1 :+: tree2) = (dxH tree1) :+: (dxH tree2)
dxH (tree1 :-: tree2) = (dxH tree1) :-: (dxH tree2)
dxH (tree1 :*: tree2) = (tree2 :*: dxH tree1) :+: (tree1 :*: dxH tree2)
dxH (tree1 :/: tree2) = ((dxH tree1) :/: tree2) :-: ((tree1 :*: dxH tree2) :/: (tree2 :*: tree2))

simpleGG :: (Num a, Eq a) => (Polynom a) -> (Polynom a)
simpleGG (pol1 :+: pol2) = simple ((simpleGG pol1) :+: (simpleGG pol2))
simpleGG (pol1 :-: pol2) = simple ((simpleGG pol1) :-: (simpleGG pol2))
simpleGG (pol1 :*: pol2) = simple ((simpleGG pol1) :*: (simpleGG pol2))
simpleGG (pol1 :/: pol2) = simple ((simpleGG pol1) :/: (simpleGG pol2))
simpleGG pol = simple pol

simple :: (Num a, Eq a) => (Polynom a) -> (Polynom a)
simple ((Con 1) :*: Param) = Param
simple (Param :*: (Con 1)) = Param
simple (pol :+: (Con 0)) = pol
simple (pol :-: (Con 0)) = pol
simple (pol :*: (Con 1)) = pol
simple (pol :*: (Con 0)) = Con 0
simple ((Con 0) :*: pol) = Con 0
simple ((Con 0) :+: pol) = pol
simple ((Con 0) :-: pol) = pol
simple ((Con 1) :*: pol) = pol
simple ((Con 0) :/: _) = Con 0
simple ((Con n1) :+: (Con n2)) = Con (n1 + n2)
simple ((Con n1) :-: (Con n2)) = Con (n1 - n2)
simple ((Con n1) :*: (Con n2)) = Con (n1 * n2)
simple pol = pol

instance (Show a) => Show (Polynom a) where
	show Param = "x"
	show (Con a) = show a
	show (pol1 :+: pol2) = (show pol1) ++ '+':(show pol2)
	show (pol1 :-: pol2) = (show pol1) ++ '-':(show pol2)
	show (pol1 :*: pol2) = (show pol1) ++ '*':(show pol2)
	show (pol1 :/: pol2) = (show pol1) ++ '/':(show pol2)

testExpr = (Param :*: Param) :-: (Con 5)

testExec = show $ dx testExpr