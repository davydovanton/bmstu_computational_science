module MathFunctions
( fFunction
, alphaFunction
, phiFunction
, analyticFunction
) where

fFunction :: Double -> Double
fFunction t = tan(t)

alphaFunction :: Double -> Double
alphaFunction t = t^2 - (log . cos) t

phiFunction :: Double -> Double
phiFunction x = x^2

analyticFunction :: Double -> Double -> Double
analyticFunction x t = (x - t)^2 - (log . cos) t
