/* JScriptDebuger */

//JsDoctor = function()
//{
//
//}
JsDoctor = {};
//JsDoctor.prototype.getLogger = function(){
//	var Jslogger = window["JsLogger"];
//	if(!Jslogger){
//		Jslogger = new JsDoctr();
//		window["JsLogger"] = Jslogger;
//	}
//	return Jslogger;
//}

JsDoctor.log = function(format, arg1, arg2) {
	var console = this._getConsole();
		console.Collapsed = true;
	this._collapseState = {width: console.style.width, height: console.style.height};
	this._expandState = {width: "50px", height: "20px"};
		
	if (true) {
		var msg = format;

		if (typeof msg !== "undefined" && msg !== null) {
			var index;
			if (typeof msg === "string") {
				var array = format.match(/\{(\d+)\}/g);
				if (array) {
					for (var i = 0; i < array.length; i++) {
						index = array[i];
						index = parseInt(index.substr(1, index.length - 2)) + 1;
						msg = msg.replace(array[i], arguments[index]);
					}
				}
			}
		}

		var span = document.createElement("SPAN");
		span.innerHTML = msg;
		this._output.appendChild(span);
		span.scrollIntoView();

		return span;
	}
}

JsDoctor._getConsole = function() {
	var console = this._console;

	if (!console) {
		var div = document.createElement("DIV");
			div.setAttribute("id", "doctor_console");
		
		document.body.appendChild(div);
		this._console = console = div;
		
		var toolbar = document.createElement("DIV");
			toolbar.setAttribute("id", "doctor_console_toolbar");

		console.appendChild(toolbar);
		this._toolbar = toolbar;

		var container = document.createElement("DIV");
			container.setAttribute("id", "doctor_console_container");

		console.appendChild(container);
		this._output = container;

		var btn;

		btn = document.createElement("SPAN");
		btn.innerHTML = "收缩";

		this._toolbar.appendChild(btn);
		//btn.attachEvent("onclick", this.CollapseOrExpand());
		addEvent(btn, "click", this.CollapseOrExpand());		
		btn = document.createElement("SPAN");
		btn.innerHTML = "清除";

		this._toolbar.appendChild(btn);
		//btn.attachEvent("onclick", this.clearConsole());
		addEvent(btn, "click", this.clearConsole());
		btn = document.createElement("SPAN");
		btn.innerHTML = "关闭";

		this._toolbar.appendChild(btn);
		//btn.attachEvent("onclick", this.hideConsole());
		addEvent(btn, "click", this.hideConsole());	
	}

	return console;
}
	
JsDoctor.showConsole =
	function() {
		this._getConsole().style.display = "";
	}
	
JsDoctor.hideConsole = function(){
	var me = this;
	return function() {
		var console = me._console;

		if (console) {
//			console.style.display = "none";
			document.body.removeChild(console);
			me._console = null;
		}
	}
}	
JsDoctor.clearConsole = function(){
	var me = this;
	return function() {
		me._output.innerHTML = "";
	}
}
JsDoctor.CollapseOrExpand = function()
{
	var me = this;
	return function()
	{
		if(me._console.Collapsed)
		{
			me._output.style.display = "none";
			me._toolbar.childNodes[1].style.display = "none";
			me._toolbar.childNodes[2].style.display = "none";
			me._toolbar.childNodes[0].innerHTML = "展开";
			me._console.style.width = me._expandState.width;
			me._console.style.height = me._expandState.height;
			me._console.Collapsed = false;	
		}else
		{
			me._console.style.width = me._collapseState.width;
			me._console.style.height = me._collapseState.height;		
			me._output.style.display = "";
			me._toolbar.childNodes[1].style.display = "";
			me._toolbar.childNodes[2].style.display = "";
			me._toolbar.childNodes[0].innerHTML = "收缩";
			me._console.Collapsed = true;
		}
	}
}

function addEvent(node, eventType, eventHandle){
    if (node.attachEvent) {//IE
        if (eventType.indexOf('on')) {
            eventType = 'on' + eventType;
        }
        node.attachEvent(eventType, eventHandle);
    }
    else {//FF
        if (!eventType.indexOf('on')) {
            eventType = eventType.substring(2, eventType.length);
        }
        node.addEventListener(eventType, eventHandle, false);
    }
    return eventHandle;
}