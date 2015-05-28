import Test.HUnit
import Data.Map (Map)
import qualified Data.Map as Map

signumChar ::  (Num a, Eq a) => a -> Char
signumChar x | signum x == 0  = ' '
			 | signum x == 1  = '+'
			 | otherwise = '-'

showDigit :: (Eq a, Show a, Num a) => (a, b) -> String
showDigit x | fst x == 0 = ""
			| fst x == 1 = "x"
			| otherwise = "x^" ++ (show $ fst x)

showMonom :: (Eq b, Show b, Num b) => (Int, b) -> Bool -> String
showMonom x bool | snd x == 0 = ""
				 | snd x == 1 = (if bool then "" else " + ") ++ showDigit x
				 | snd x == -1 = " - " ++ showDigit x
				 | bool == True = (show $ snd x) ++ (showDigit x)
				 | otherwise = " " ++ (signumChar $ snd x) : " " ++ (show $ abs $ snd x) ++ (showDigit x)

type (Polynom a) = Map Int a

polFromList :: (Num a) => [(Int, a)] -> (Polynom a)
polFromList xs = Map.fromList xs

showPol :: (Show a, Num a, Eq a) => Polynom a -> String
showPol pol | xp == [] = ""
			| otherwise = (showMonom (head xp) True) ++ (showH $ tail xp) where
							xp = Map.toList pol
							showH [] = ""
							showH (x:xs) = (showMonom x False) ++ (showH xs)

	
plus :: (Num a) => Polynom a -> Polynom a -> Polynom a
plus xp yp = Map.unionWith (+) xp yp

dx :: (Num a, Num b) => (Polynom a) -> (Polynom a)
dx pol = Map.mapKeys (subtract 1) (Map.delete 0 npol) where
		npol = Map.mapWithKey (\key x -> fromIntegral key * x) pol

mult :: (Num a) => Polynom a -> Polynom a -> Polynom a
mult pol1 pol2 =  Map.fromListWith ( + ) (multi (\(a, b) (c, d) -> (a + c, b * d)) (Map.toList pol1) (Map.toList pol2)) where
																															multi :: (a -> a -> a) -> [a] -> [a] -> [a]
																															multi _ [] _ = []
																															multi _ _ [] = []
																															multi f xs ys = [f x y | x <- xs, y <- ys]