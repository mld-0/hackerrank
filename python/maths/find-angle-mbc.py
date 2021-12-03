import math

if __name__ == '__main__':
    AB = 1
    BC = 100

    #   Ongoing: 2021-11-09T00:24:16AEDT _hackerrank, find-angle-mbc, invalid when submitted, appears to be correct (call it) lying-eyes when run locally, second solution works, (recognition that MBC == AMB), (use of 'int' function) <- use of round(int()) instead of int(round())?
    #   invalid:
    theta_ACB = math.atan2(BC,AB)
    theta_MBC = math.pi/2 - theta_ACB
    theta_MBC_deg = round(math.degrees(theta_MBC))
    print(theta_MBC_deg, end=u'\N{DEGREE SIGN}\n')
    #   correct:
    theta_ACB = math.atan2(BC,AB)
    theta_MBC_deg = int(round(90 - math.degrees(theta_ACB)))
    print(theta_MBC_deg, end=u'\N{DEGREE SIGN}\n'
    #   (also) correct:
    print(str(int(round(math.degrees(math.atan2(AB,BC))))) , end=u'\N{DEGREE SIGN}\n')

