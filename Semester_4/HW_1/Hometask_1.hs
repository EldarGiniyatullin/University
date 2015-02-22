module Main where

factorial 0 = 1
factorial x = product [1..x]

main = print (factorial 9)