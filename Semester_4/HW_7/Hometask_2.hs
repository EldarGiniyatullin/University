import System.Random
import Control.Monad.State
import Data.Time.Clock.POSIX

data Tree a = Empty | Node {value :: a, left :: (Tree a), right :: (Tree a)} deriving (Show)

mapTreeM :: (RandomGen g) => (g -> (Int, g)) -> Tree a -> State g (Tree Int)
mapTreeM _ Empty = return Empty
mapTreeM f (Node val lt rt) = do
								 	oldGen <- get
									let (nval, newGen) = f oldGen
									put newGen
									nrt <- mapTreeM f rt
									nlt <- mapTreeM f lt
									return (Node nval nlt nrt)

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



main = do
			num <- (round . ((*) 10000) . snd . properFraction) `fmap` getPOSIXTime
			print $ show $ evalState (mapTreeM (randomR (-100, 100)) testTree) (mkStdGen num)