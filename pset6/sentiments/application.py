from flask import Flask, redirect, render_template, request, url_for

import os
import sys
import helpers
from analyzer import Analyzer

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/search")
def search():

    # validate screen_name
    screen_name = request.args.get("screen_name", "").lstrip("@")
    if not screen_name:
        return redirect(url_for("index"))

    # absolute paths to lists
    pos = os.path.join(sys.path[0], "positive-words.txt")
    neg = os.path.join(sys.path[0], "negative-words.txt")

    # instantiate analyzer
    analyzer = Analyzer(pos, neg)
    
    # get screen_name's most recent 100 tweets
    tweets = helpers.get_user_timeline(screen_name, 100)
    
    # return to index if screen_name doesn't exist
    if tweets == None:
        return redirect(url_for("index"))
        
    # create pos, negative and neutral count
    pos, neg, neutral = 0, 0, 0
    
    # analyze each tweet & increase corresponding sentimen count
    for tweet in tweets:
        score = analyzer.analyze(tweet)
        if score > 0.0:
            pos += 1
        elif score < 0.0:
            neg += 1
        else:
            neutral += 1

    # generate chart
    chart = helpers.chart(pos, neg, neutral)

    # render results
    return render_template("search.html", chart=chart, screen_name=screen_name)
