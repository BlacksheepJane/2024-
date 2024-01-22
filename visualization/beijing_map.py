from pyecharts.charts import Geo
from pyecharts.faker import Faker
from pyecharts.globals import GeoType
from pyecharts.charts import Map #导入地图模块
from pyecharts import options as opts
import webbrowser

import pandas as pd
path='Case1-vertex.xlsx'
num=pd.read_excel(path,header=1,usecols=[0])
longitude=pd.read_excel(path,usecols=[1])
latitude=pd.read_excel(path,usecols=[2])

Beijing_city=Geo(init_opts=opts.InitOpts(width="1600px",height="1200px"))

Beijing_city.add_schema(maptype="北京",center=[116.3780426,39.94038724])
for i in num[0]:
    Beijing_city.add_coordinate(i,longitude.iat[i,0],latitude.iat[i,0])
    data_pair=[(i,int(i/100))]
    if i > 9500 and i<10500:
        Beijing_city.add('',data_pair,symbol_size=3,is_large=True,blur_size =3,point_size=3,color='red')
    # elif i<15000:
    #     Beijing_city.add('',data_pair,symbol_size=3,is_large=True,blur_size =3,point_size=3,color='blue')
    # else:
    #     Beijing_city.add('',data_pair,symbol_size=3,is_large=True,blur_size =3,point_size=3,color='#98FB98')
Beijing_city.set_global_opts(title_opts=opts.TitleOpts(title="北京地图",pos_right="center"))
results=Beijing_city.render(path="北京地图.html")
webbrowser.open(results)