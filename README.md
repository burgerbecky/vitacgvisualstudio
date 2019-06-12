Playstation Vita CG Visual Studio 2010+ Integration
===================================================

**Or, how do I include PS Vita shader code in my project?**

Copyright 2015 by Rebecca Ann Heineman becky@burgerbecky.com

It is released under an MIT Open Source license. Please see LICENSE
for license details. Yes, you can use it in a
commercial title without paying anything, just give me a credit.
Please? It's not like I'm asking you for money!

What is Playstation Vita CG Visual Studio 2010+ Integration?
------------------------------------------------------------

This is a plug in for Visual Studio 2010 or higher that will
allow files with the VITACG extension to automatically be compiled
with the psp2cgc tool found in the Playstation Vita SDK. 

The tool will be listed as "Vita CG Compiler Tool"

What does it require?
--------------------

Visual Studio 2010 and the Playstation Vita SDK. Only licensed Playstation
Vita developers can download the SDK. Don't ask me for it. Ask Sony.

How do I use it?
----------------

Copy the contents of the "plugin" folder to the folder 
<em>C:\Program Files (x86)\MSBuild\Microsoft.Cpp\v4.0\BuildCustomizations</em>

Find this line in your .vcxproj file
<em>&lt;Import Project="$(VCTargetsPath)\Microsoft.Cpp.props"/&gt;</em>

Insert this after it
<pre>&lt;ImportGroup Label="ExtensionSettings"/&gt;
	&lt;Import Project="$(VCTargetsPath)\BuildCustomizations\vitacg.props" /&gt;
&lt;/ImportGroup/&gt;
</pre>

Find this line near the end of your .vcxproj file
<em>&lt;Import Project="$(VCTargetsPath)\Microsoft.Cpp.targets" /&gt;</em>

Insert this after it.
<pre>&lt;ImportGroup Label="ExtensionTargets"&gt;
	&lt;Import Project="$(VCTargetsPath)\BuildCustomizations\vitacg.targets" /&gt;
&lt;/ImportGroup&gt;
</pre>

This is great/sucks! But, how can I change/rewrite/steal the tool?
----------------------------------------------------

The source code to the tool is in the folder "source". It will require Burgerlib for some
subroutines. https://github.com/Olde-Skuul/KitchenSink has the binaries of the library
and https://github.com/Olde-Skuul/burgerlib has the source to the library.
