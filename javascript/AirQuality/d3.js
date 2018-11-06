//Air Qaulity API
function getAirQuality() {
    console.log("it worked");
    var cityname = 'Beijing';
    var airUrl = "https://api.openaq.org/v1/measurements?city=" + cityname;

    //margin convention

    //define SVG
    var svg = d3.select(".Beijing");
    var margin = {
        top: 10,
        right: 10,
        bottom: 10,
        left: 40
    };
    var width = 700 - margin.right - margin.left;
    var height = 550 - margin.top - margin.bottom;


    svg.append("g")
        .attr("transfrom", "translate(" + margin.left + "," + margin.right + ")");

    //load Air quality data, anynmous function
    d3.json(airUrl, function (error, data) {
        if (error) console.log("error, data not load");

        console.log(data)
        //creating empety array for date and pm2.5 value
        var airData = new Array();
        var dateData = new Array();

        for (var i = 0; i < 100; i++) {
            //put data in the new array
            airData.push(data["results"][i].value);
            dateData.push(data["results"][i].date.local);
        };

//         console.log(dateData);

        var y = d3.scaleLinear()
            .domain([0, Math.max(...airData)])
            .range([0, height]);
//        console.log(airData);


        var x = d3.scaleLinear()
            .domain([0, dateData.length])
            .range([0, width]);

        var color = d3.scaleQuantize()
            .domain([0, Math.max(...airData)])
            .range(["#60c5ba","#f9c00c","#c03546","#512645"]);

        var axis = d3.axisLeft(y)
            .ticks(10)
            .scale(x);

        var bars = svg.selectAll("rect")
            .data(airData)

        bars.enter()
            .append("rect")
            .attr("x", function (d, i) {
                return i*9;
            })
            .attr("y", function (d) {
                return height - y(d, y) - 20
            })
            .transition().duration(1500)
            .delay(function (d, i) {
                return i * 50
            })
            .attr("height", function (d) {
                return y(d)
            })
            .attr("width", 4)
            .attr("fill", function (d) {
                return color(d)
            })
        svg.exit().remove();

    });

}

getAirQuality()
