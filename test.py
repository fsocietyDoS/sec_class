import pandas as pd

df = pd.read_csv(r'/Users/davidbareyan/anomaly_detection/test/data.csv')

df = pd.read_csv("data.csv", skiprows=1, names=["Time", "LoadAverage"])
df["Time"] = pd.to_datetime(df["Time"], unit="ms")

df.to_csv("converted_data.csv", index=False)