import WebGL from './WebGL.js';
import * as THREE from 'https://cdn.skypack.dev/three@0.129.0/build/three.module.js';
import { GLTFLoader } from 'https://cdn.skypack.dev/three@0.129.0/examples/jsm/loaders/GLTFLoader.js';
import { OrbitControls } from 'https://cdn.skypack.dev/three@0.129.0/examples/jsm/controls/OrbitControls.js';

const scene = new THREE.Scene();
const camera = new THREE.PerspectiveCamera( 75, window.innerWidth / window.innerHeight, 0.1, 1000 );
camera.position.z = 7;
const renderer = new THREE.WebGLRenderer();
renderer.setSize( window.innerWidth, window.innerHeight );
document.body.appendChild( renderer.domElement );

const loading_div = document.createElement("div");
loading_div.classList.add("loadingtext");
loading_div.textContent = "Loading";
document.body.appendChild(loading_div);

var manager = new THREE.LoadingManager();
manager.onLoad = function () {
	loading_div.textContent = "";
};
manager.onProgress = async ( url, itemsLoaded, itemsTotal ) => {
	let progress = (itemsLoaded / itemsTotal * 100);
	if (itemsTotal <= 2)
		progress = 0;
	var str = Math.ceil(progress) + '%';
	loading_div.textContent = str
};

const loader = new GLTFLoader(manager);
loader.load(
	'files/roulette_table.glb',
	function ( gltf ) {
		scene.add( gltf.scene );
	}, undefined, function ( error ) {
		console.error( error );
	}
);

scene.background = new THREE.Color(0xc0c0c0);
const ambientLight = new THREE.AmbientLight(0xffffff, 0.5);
scene.add(ambientLight);
const directionalLight = new THREE.DirectionalLight(0xffffff, 0.5);
directionalLight.position.set(0, 1, 0);
scene.add(directionalLight);

const controls = new OrbitControls( camera, renderer.domElement );
controls.target.set( 0, 0, 0 );
controls.update();

function animate() {
	requestAnimationFrame( animate );
	renderer.render( scene, camera );
}

if ( WebGL.isWebGLAvailable() ) {
	animate();
} else {
	const warning = WebGL.getWebGLErrorMessage();
	document.getElementById( 'container' ).appendChild( warning );
}

function onWindowResize() {
	camera.aspect = window.innerWidth / window.innerHeight;
	camera.updateProjectionMatrix();
	renderer.setSize( window.innerWidth, window.innerHeight );
}
window.addEventListener("resize", () => {
	onWindowResize();
});
