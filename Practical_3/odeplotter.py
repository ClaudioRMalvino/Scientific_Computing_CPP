import matplotlib.pyplot as plt
import numpy as np


def main() -> None:
    file = "ode.dat"
    data = np.loadtxt(file, delimiter=",")
    x = data[:, 0]
    y = data[:, 1]

    plt.plot(x, y)
    plt.title("Euler Method")
    plt.xlabel("t")
    plt.ylabel("f(y,t)")
    plt.show()


if __name__ == "__main__":
    main()
